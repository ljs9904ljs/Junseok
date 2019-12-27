import myScalar
import myString

class myMatrix:

	# for initialize empty matrix
	def __initEmpty(self, row, col):
		if row <=0 or col <= 0:
			raise NameError('Initialization Fail')
		self.row = row
		self.col = col
		self.val = [([float()] * col) for i in range(row)]

	def __init__(self, row, col, val=[]):
		# for empty matrix
		if not val:
			self.__initEmpty(row,col)
			return
		# check the input parameter
		if type(val)!=list or not all(isinstance(v,float) for v in val) or len(val)!=row*col or row <=0 or col <= 0:
			raise NameError('Initialization Fail')
		# member variable assign
		self.row = row
		self.col = col
		self.val = []
		for i in range(row):
			self.val.append([])
			for j in range(col):
				self.val[i].append(val[col*i+j])

	def __str__(self): # Make myMatrix to string value for scoring
		return str(self.val)

############ DO NOT change the above lines ############

	def addScalar(self,op):
		res = myMatrix(self.row,self.col)
		for i in range(len(self.val)):
			for j in range(len(self.val[i])):
				res.val[i][j] = self.val[i][j] + op.val
		return res


	def __add__(self, op):
		if type(op) is myScalar.myScalar:
			return self.addScalar(op)
		else:
			raise NameError('Not defined')