
class StatementIf < Struct.new(:condition, :true_statement, :false_statement)
  def to_s
    "if (#{condition}) { #{true_statement} } else { #{false_statement} }"
  end

  def inspect
    "<<#{self}>>"
  end

  def execute(environment)
    if condition.evaluate(environment).as_boolean
      true_statement.execute(environment)
    else
      false_statement.execute(environment)
    end
  end
end
