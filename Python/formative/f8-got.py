x=0
def f():
	global x
	
	x=(x+1)
	return x


def main():
	global x
	
	return (f()+f())



# Invoke main as the starting point
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
