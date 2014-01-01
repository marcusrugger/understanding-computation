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
  If.new(
    Variable.new(:x),
    Assign.new(:y, Number.new(1)),
    Assign.new(:y, Number.new(2))
    ),
  { x: Boolean.new(false) }
  ).run
