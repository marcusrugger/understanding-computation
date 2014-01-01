
class Variable < Struct.new(:name)

  def to_s
    name.to_s
  end

  def inspect
    "<<#{self}>>"
  end

  def assign(obj, environment)
    environment[name] = obj
  end

  def evaluate(environment)
    environment[name].evaluate(environment)
  end

end
