
class OperatorSubtract < Struct.new(:left, :right)

  def to_s
    "#{left} - #{right}"
  end

  def inspect
    "<<#{self}>>"
  end

  def evaluate(environment)
    left_result = left.evaluate(environment)
    right_result = right.evaluate(environment)
    left_result.subtract(right_result)
  end

end
