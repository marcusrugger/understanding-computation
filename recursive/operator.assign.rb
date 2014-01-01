
class Assign < Struct.new(:left, :right)

  def to_s
    "#{left} = #{right}"
  end

  def inspect
    "<<#{self}>>"
  end

  def evaluate(environment)
    result = right.evaluate(environment)
    left.assign(result, environment)
  end

end
