
class Variable < Struct.new(:name)

  def to_s
    name.to_s
  end

  def inspect
    "<<#{self}>>"
  end

  def evaluate(environment)
    environment[name].evaluate(environment)
  end

  def assign(obj, environment)
    environment[name] = obj
  end

end
