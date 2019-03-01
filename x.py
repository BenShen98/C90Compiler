
foo(x)=0
def main():
	
	x=5
	
	y=0
	y=foo(x)
	return (y-123)


def foo(x):
	
	y=123
	return (x+y)



# Invoke main as the starting point
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
