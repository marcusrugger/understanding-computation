require "./machine"
require "./number"
require "./variable"
require "./add"
require "./multiply"
require "./assign"

environment = { x: Number.new(2), y: Number.new(3) }

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
