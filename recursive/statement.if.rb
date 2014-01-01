
class If < Struct.new(:condition, :consequence, :alternative)
  def to_s
    "if (#{condition}) { #{consequence} } else { #{alternative} }"
  end

  def inspect
    "<<#{self}"
  end

  def execute(environment)
    case condition.evaluate(environment)
    when Boolean.new(true)
      consequence.execute(environment)
    when Boolean.new(false)
      alternative.execute(environment)
    end
  end
end
