package csci152.impl;

import csci152.adt.Stack;

public class LinkedListStack<T> implements Stack<T>{
	private int size;
	private Node<T> top;
	
	/**
	 * creating a linked list stack
	 * with size = 0 and no elements
	 */
	public LinkedListStack() {
		size = 0;
		top = null;
	}
	
	/**
	 * Pushes an object into the stack
	 * @param value object
	 */
	public void push(T value) {
		Node<T> current = new Node<T>(top, value);
		top = current;
		size++;
	}
	
	/**
	 * Pops out an object from stack
	 * @throws Exception of emptiness
	 * @return T object
	 */
	public T pop() throws Exception {
		if (size > 0) {
			Node<T> current = top;
			top = top.getLink();
			size--;
			return (T)current.getValue();
		} else
			throw new Exception("Stack is empty");
	}
	
	/**
	 * Returns the size of stack
	 * @return size of stack 
	 */
	public int getSize() {
		return size;
	}
	
	/**
	 * Clears a stack
	 * and making top to NULL
	 */
	public void clear() {
		// here I making all nodes NULL so the garbage collector can delete them
		Node<T> current = top;
		while (current != null) {
			Node<T> toNull = current;
			current = current.getLink();
			toNull = null;
		}
		top = null;
		size = 0;
	}
	
	/**
	 * Returns a reversed version of stack 
	 * This used in toString method because in LinkedListStack we cannot go from bottom 
	 * so we need to copy a stack to another, the second stack will be reversed
	 * @return stack
	 */
	public LinkedListStack<T> reverse() {
		Node<T> current = top;
		LinkedListStack<T> rstack = new LinkedListStack<T>();
		while (current != null) {
			rstack.push(current.getValue());
			current = current.getLink();
		}
		return rstack;
	}
	
	/**
	 * Returns the last node of a stack
	 * @return top
	 */
	public Node<T> getTop() {
		return top;
	}
	
	public String toString() {
		String msg = "bottom [ ";
		Node<T> current = new Node<T>();
		// Node current points to the TOP node of reversed stack
		// i.e. points to the BOTTOM of the original stack
		current = this.reverse().getTop();
		while (current != null) {
			msg += " [ " + current.getValue() + " ] ";
			current = current.getLink();
		}
		return msg + "] top";
	}
}
