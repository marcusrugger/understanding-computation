
class Number < Struct.new(:value)
  
  def to_s
    value.to_s
  end

  def inspect
    "<<#{self}>>"
  end

  def evaluate(environment)
    self
  end

  def add(obj)
    Number.new(value + obj.value)
  end

  def subtract(obj)
    Number.new(value - obj.value)
  end

  def multiply(obj)
    Number.new(value * obj.value)
  end

  def divide(obj)
    Number.new(value / obj.value)
  end

end
