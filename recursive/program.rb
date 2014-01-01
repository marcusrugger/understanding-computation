require "./machine"
require "./term.boolean"
require "./term.number"
require "./term.string"
require "./term.variable"
require "./operator.assign"
require "./operator.equal"
require "./operator.less_than"
require "./operator.greater_than"
require "./operator.add"
require "./operator.subtract"
require "./operator.multiply"
require "./operator.divide"
require "./statement.do_nothing"
require "./statement.statement"
require "./statement.sequence"
require "./statement.if"
require "./statement.while"

environment = { x: Number.new(0) }

condition_expression = LessThan.new(Variable.new(:x), Number.new(5))
body_expression = Assign.new(Variable.new(:x), Add.new(Variable.new(:x), Number.new(1)))
body_statement = Statement.new(body_expression)
while_statement = While.new(condition_expression, body_statement)


puts while_statement

puts environment
while_statement.execute(environment)
puts environment

a = SimpleString.new("Hello world")
b = SimpleString.new("Goodbye")

expression = Add.new(a, b)

c = expression.evaluate({})

puts c
