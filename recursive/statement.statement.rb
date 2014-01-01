
class Statement < Struct.new(:expression)
  def to_s
    "#{expression}"
  end

  def inspect
    "<<#{self}>>"
  end

  def execute(environment)
    environment[:last_result] = expression.evaluate(environment)
    environment
  end
end
