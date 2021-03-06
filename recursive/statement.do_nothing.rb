
class StatementDoNothing
  def to_s
    "do-nothing"
  end

  def inspect
    "<<#{self}>>"
  end

  def ==(other_statement)
    other_statement.instance_of?(DoNothing)
  end

  def execute(environment)
    environment
  end
end
