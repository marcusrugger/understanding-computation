
class Machine < Struct.new(:expression, :environment)
  def run
    puts expression.evaluate(environment).value
  end
end
