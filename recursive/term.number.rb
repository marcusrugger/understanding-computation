
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

  def as_boolean
    value != 0
  end

  def as_number
    value
  end

  def assign(right_side, environment)
    raise 'Assignment operator (=) is not supported by number term'
  end

  def boolean_or(right_side)
    Boolean.new(as_boolean || right_side.as_boolean)
  end

  def boolean_and(right_side)
    Boolean.new(as_boolean && right_side.as_boolean)
  end

  def boolean_not
    Boolean.new(!as_boolean)    
  end

  def equal(right_side)
    Boolean.new(as_number == right_side.as_number)
  end

  def less_than(right_side)
    Boolean.new(as_number < right_side.as_number)
  end

  def greater_than(right_side)
    Boolean.new(as_number > right_side.as_number)
  end

  def add(right_side)
    Number.new(as_number + right_side.as_number)
  end

  def subtract(right_side)
    Number.new(as_number - right_side.as_number)
  end

  def multiply(right_side)
    Number.new(as_number * right_side.as_number)
  end

  def divide(right_side)
    Number.new(as_number / right_side.as_number)
  end

end
