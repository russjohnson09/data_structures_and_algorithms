/* The IntegerNode class
   Anderson, Franceschi
*/

public class IntegerNode
{
  private int data;
  private IntegerNode next;

  /** default constructor
  *   sets data to 0, and next to null
  */
  public IntegerNode( )
  {
    data = 0;
    next = null;
  }

  /** overloaded constructor
  *   @param   newData  data value
  */
  public IntegerNode( int  newData )
  {
    setData( newData );
    next = null;
  }

  /** accessor for data
  *   @return   the value of the node
  */
  public int getData( )
  {
    return data;
  }

  /** accessor for next
  *   @return   the reference to the next node
  */
  public IntegerNode getNext( )
  {
    return next;
  }

  /** mutator for data
  *   @param    newData   the new value for the node
  */
  public void setData( int newData )
  {
    data = newData;
  }

  /** mutator for next
  *   @param    nd   the new value for next
  */
  public void setNext( IntegerNode  nd )
  {
    next = nd;
  }
}
