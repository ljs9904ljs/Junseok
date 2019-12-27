import myScalar
import myMatrix

class myString:

	def __init__(self, val):
		# check the input parameter
		if type(val) != str:
			raise NameError('Initialization Fail')
		# member variable assign
		self.val = val
		
	def __str__(self): # Make myString to string value for scoring
		return self.val

############ do not change the above lines ############
