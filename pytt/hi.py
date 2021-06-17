lis=    'camk'

l1=['cam','mak','amk','kammm']

def ck(elem,arr,abet):
	st=''
	for i in range(len(max(arr, key=len))):
		#print(st)
		if i<len(elem):
			st=st+ohe(abet,elem[i])
		else:
			st=st+ohe(abet,'_')
	return int(st,2)
	
def ohe(hs, n):
	return "{0:b}".format( 2**(hs.index(n))).zfill(len(hs)) if n in hs else ('0'*len(hs))
	
print(l1)
l2=sorted(l1,key=lambda x: ck(x,l1,lis))
print(l2)

