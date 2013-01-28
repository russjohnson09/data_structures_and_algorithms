/* The IntegerLinkedListTest class
   Anderson, Franceschi
*/

public class IntegerLinkedListTest
{
  public static void main( String [ ] args )
  {
    // construct empty IntegerLinkedList
    IntegerLinkedList numbers = new IntegerLinkedList( );
    System.out.println( "Number of items in the list: "
     + numbers.getNumberOfItems( ) + "\n" + numbers );

    numbers.insert( 7 );  // insert in empty list
    System.out.println( "Number of items in the list: "
     + numbers.getNumberOfItems( ) + "\n" + numbers );

    numbers.insert( 2 );  // insert in list with one item
    System.out.println( "Number of items in the list: "
     + numbers.getNumberOfItems( ) + "\n" + numbers );

    numbers.insert( 5 );  // insert in list with two items
    System.out.println( "Number of items in the list: "
     + numbers.getNumberOfItems( ) + "\n" + numbers );

    if ( ! numbers.remove( 8 ) )   // unsuccessful - not in list
        System.out.println( "8 could not be removed:" );

    if ( numbers.remove( 2 ) )     // successful
        System.out.println( "2 was successfully removed:" );
    System.out.println( "Number of items in the list: "
       + numbers.getNumberOfItems( ) + "\n" + numbers );

    if ( numbers.remove( 7 ) )    // successful
        System.out.println( "7 was successfully removed:" );
    System.out.println( "Number of items in the list: "
       + numbers.getNumberOfItems( ) + "\n" + numbers );

    if ( numbers.remove( 5 ) )    // successful
        System.out.println( "5 was successfully removed:" );
    System.out.println( "Number of items in the list: "
       + numbers.getNumberOfItems( ) + "\n" + numbers );

    if ( ! numbers.remove( 8 ) )  // unsuccessful - empty list
        System.out.println( "8 could not be removed:" );
    System.out.println( "Number of items in the list: "
       + numbers.getNumberOfItems( ) + "\n" + numbers );
  }
}
