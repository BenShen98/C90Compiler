
x=0
def f():
	
	x=(x+1)
	return x


def main():
	
	return (f()+f())



# Invoke main as the starting point
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
