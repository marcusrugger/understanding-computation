
class TermString < Struct.new(:string)
  
  def to_s
    string
  end

  def inspect
    "<<#{self}>>"
  end

  def evaluate(environment)
    self
  end

  def as_boolean
    string.length > 0
  end

  def as_number
    raise 'Attempt to cast SimpleString as number'
  end

  def as_string
    string
  end

  def assign(right_side, environment)
    raise 'Assignment operator (=) is not supported by number term'
  end

  def boolean_or(right_side)
    raise 'Not supported'
  end

  def boolean_and(right_side)
    raise 'Not supported'
  end

  def boolean_not
    raise 'Not supported'
  end

  def equal(right_side)
    TermBoolean.new(as_string.eql?(right_side.as_string))
  end

  def less_than(right_side)
    TermBoolean.new((as_string <=> right_side.as_string) < 0)
  end

  def greater_than(right_side)
    TermBoolean.new((as_string <=> right_side.as_string) > 0)
  end

  def add(right_side)
    TermString.new(as_string + right_side.as_string)
  end

  def subtract(right_side)
    raise 'Not supported'
  end

  def multiply(right_side)
    raise 'Not supported'
  end

  def divide(right_side)
    raise 'Not supported'
  end

end
