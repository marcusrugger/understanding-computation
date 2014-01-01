require "./machine"
require "./number"
require "./boolean"
require "./variable"
require "./less_than"
require "./add"
require "./multiply"
require "./do_nothing"
require "./assign"
require "./if"
require "./sequence"
require "./while"

environment = { x: Number.new(2), y: Number.new(3) }

=begin
Machine.new(
  Assign.new(
    :x,
    Add.new(
      Multiply.new(Variable.new(:x), Variable.new(:y)),
      Multiply.new(Variable.new(:x), Variable.new(:y))
      )
    ),
  environment
  ).run
=end

Machine.new(
  While.new(
    LessThan.new(Variable.new(:x), Number.new(5)),
    Assign.new(:x, Add.new(Variable.new(:x), Number.new(1))),
    ),
  { x: Number.new(1) }
  ).run
