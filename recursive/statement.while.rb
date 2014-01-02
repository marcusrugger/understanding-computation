
class StatementWhile < Struct.new(:condition, :body)
  def to_s
    "while (#{condition}) { #{body} }"
  end

  def inspect
    "<<#{self}>>"
  end

  def execute(environment)
    while condition.evaluate(environment).as_boolean do
      environment = body.execute(environment)
    end
    environment
  end
end
