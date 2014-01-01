require "./machine"
require "./term.boolean"
require "./term.number"
require "./term.variable"
require "./operator.assign"
require "./operator.add"
require "./operator.subtract"
require "./operator.multiply"
require "./operator.divide"
require "./operator.assign"
require "./statement.do_nothing"
require "./statement.statement"
require "./statement.if"

a = Number.new(2)
b = Number.new(3)
c = Number.new(4)
d = Number.new(5)

multiply_b_c = Multiply.new(b, c)

add_a_result = Add.new(a, multiply_b_c)
add_result_d = Add.new(add_a_result, d)

assign_to_x = Assign.new(Variable.new(:x), add_result_d)

statement = Statement.new(assign_to_x)

puts statement

environment = {}
statement.execute(environment)

puts environment
