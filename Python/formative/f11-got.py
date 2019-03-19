def f(x):
	
	if (x>1):
		
		return (x*f((x-1)))
	else:
		
		return x


def main():
	
	return f(2)



# Invoke main as the starting point
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
