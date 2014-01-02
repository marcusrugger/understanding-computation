
class StatementSequence < Struct.new(:first, :second)
  def to_s
    "#{first}; #{second}"
  end

  def inspect
    "<<#{self}>>"
  end

  def execute(environment)
    second.execute(first.execute(environment))
  end
end
