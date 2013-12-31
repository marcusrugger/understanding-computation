require "./machine"
require "./add"
require "./multiply"
require "./variable"

environment = { x: Number.new(2), y: Number.new(3) }

Machine.new(
  Add.new(
    Multiply.new(Variable.new(:x), Variable.new(:y)),
    Multiply.new(Variable.new(:x), Variable.new(:y))
    ),
  environment
  ).run
