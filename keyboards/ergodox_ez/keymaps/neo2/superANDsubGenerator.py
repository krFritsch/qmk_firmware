import string

alphabet = list(string.digits)


""" subscript """
print('\n'*3)
subcodes = [
	'2080',
	'2081',
	'2082',
	'2083',
	'2084',
	'2085',
	'2086',
	'2087',
	'2088',
	'2089',
]
for char, code in zip(alphabet, subcodes):
	print('\t[SUB_{0}]\t = 0x{1} ,\t // subscript {0}'.format(char, code))
	
	
for char in alphabet:
	print('\tSUB_{0},'.format(char))
	
""" superscript """
print('\n'*3)
supercodes = [
	'2070',
	'00B9',
	'00B2',
	'00B3',
	'2074',
	'2075',	
	'2076',	
	'2077',	
	'2078',	
	'2079',	
]
for char, code in zip(alphabet, supercodes):
	print('\t[SUP_{0}]\t = 0x{1} ,\t // superscript {0}'.format(char, code))
	
for char in alphabet:
	print('\tSUP_{0},'.format(char))