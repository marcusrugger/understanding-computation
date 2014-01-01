
class Assignment < Struct.new(:left, :right)

  def to_s
    "#{left} = #{right}"
  end

  def inspect
    "<<#{self}>>"
  end

  def evaluate(environment)
    result = right.evaluate(environment)
    left.assign(environment, result)
    return result;
  end

end
