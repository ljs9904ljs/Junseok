import myString
import myMatrix

class myScalar:

	def __init__(self, val):
		# check the input parameter
		if type(val)!=float:
			raise NameError('Initialization Fail')
		# member variable assign
		self.val = val

	def __str__(self): # Make myScalar to string value for scoring
		return str(self.val)

############ do not change the above lines ############

	def addStr(self,op):
		res = myString.myString('')
		return myString.myString(str(self.val)+op.val)

	def __add__(self, op):
		if type(op) is myScalar:
			return myScalar(self.val+op.val)
		elif type(op) is myMatrix.myMatrix:
			return (op + self)
		elif type(op) is myString.myString:
			return self.addStr(op)
		else:
			raise NameError('Not defined')




