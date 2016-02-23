package csci152.adt;

public interface Stack<T> {
	/**
	 * Pushes a new element to the top of
	 * @throws Exception
	 */
	public void push(T value);
	
	/**
	 * Returns the top element if there is no
	 * element in the Stack it throws Exception
	 * @return the top element in the Stack
	 * @throws Exception
	 */
	public T pop() throws Exception;
	
	/**
	 * Clears the Stack i.e.
	 */
	public void clear();
	
	/**
	 * @return the size of the Stack
	 */
	public int getSize();
	
	/**
	 * @return a String representation of the Stack
	 */
	public String toString();
}
