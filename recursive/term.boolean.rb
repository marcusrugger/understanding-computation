
class TermBoolean < Struct.new(:value)
  
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
    value
  end

  def as_number
    value ? 1 : 0
  end

  def assign(right_side, environment)
    raise 'Assignment operator (=) is not supported by boolean term'
  end

  def boolean_or(right_side)
    TermBoolean.new(as_boolean || right_side.as_boolean)    
  end

  def boolean_and(term, environment)
    TermBoolean.new(as_boolean && right_side.as_boolean)
  end

  def boolean_not(environment)
    TermBoolean.new(!as_boolean)    
  end

  def equal(right_side)
    TermBoolean.new(as_boolean == right_side.as_boolean)
  end

  def less_than(right_side)
    raise 'Less-than operator (<) is not supported by boolean term'
  end

  def greater_than(right_side)
    raise 'Greater-than operator (>) is not supported by boolean term'
  end

  def add(right_side)
    raise 'Addition operator (+) is not supported by boolean term'
  end

  def subtract(right_side)
    raise 'Subtraction operator (-) is not supported by boolean term'
  end

  def multiply(right_side)
    raise 'Multiplication operator (*) is not supported by boolean term'
  end

  def divide(right_side)
    raise 'Division operator (/) is not supported by boolean term'
  end

end
