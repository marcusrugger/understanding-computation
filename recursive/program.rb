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

environment = { x: TermNumber.new(0) }

condition_expression = OperatorLessThan.new(TermVariable.new(:x), TermNumber.new(5))
body_expression = OperatorAssign.new(TermVariable.new(:x), OperatorAdd.new(TermVariable.new(:x), TermNumber.new(1)))
body_statement = Statement.new(body_expression)
while_statement = StatementWhile.new(condition_expression, body_statement)


puts while_statement

puts environment
while_statement.execute(environment)
puts environment

a = TermString.new("Hello world")
b = TermString.new("Goodbye")

expression = OperatorAdd.new(a, b)

c = expression.evaluate({})

puts c
