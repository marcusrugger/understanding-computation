require "./machine"
require "./term.number"
require "./term.variable"
require "./operator.add"
require "./operator.subtract"
require "./operator.multiply"
require "./operator.divide"
require "./operator.assignment"

environment = { x: Number.new(2), y: Number.new(3) }

Machine.new(
  Assignment.new(
    Variable.new(:a),
    Add.new(
      Multiply.new(Variable.new(:x), Variable.new(:y)),
      Multiply.new(Variable.new(:x), Variable.new(:y))
      )
    ),
  environment
  ).run

puts "a: #{environment[:a]}"
