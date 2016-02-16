# include <iostream>
using namespace std;

template<class Object>
class List;

template<class Object>
class ListItr;

template <class Object>
class ListNode
{
        ListNode(const Object & theElement = Object(),ListNode * n = NULL)
                : element( theElement ),next( n ) {
        }

        Object element;
        ListNode *next;

        friend class List<Object>;
        friend class ListItr<Object>;

};

template<class Object>
class ListItr
{
public:
        ListItr( ) : current ( NULL )

        {
        }

        bool isPastEnd( ) const
        {
                return current== NULL;
        }

        void advance( )
        {
                if( !isPastEnd( ) )
                        current = current->next;
        }

        const Object & retrieve( ) const
        {
                if( isPastEnd( ) )
                        return NULL;

                return current->element;
        }

private:
        ListNode<Object> *current;

        ListItr( ListNode<Object> *theNode ) : current( theNode ) {
        }
        friend class List<Object>;
};

template<class Object>
class List
{
public:
        List( );
        List( const List &rhs);
        ~List( );

        bool isEmpty( ) const;
        void makeEmpty( );
        ListItr<Object> zeroth( ) const;
        ListItr<Object> first( ) const;
        void insert( const Object & x, const ListItr<Object> & p );
        ListItr<Object> find( const Object &x ) const;
        ListItr<Object> findPrevious( const Object &x ) const;
        int remove( const Object & x );

        const List & operator=( const List &rhs);

private:
        ListNode<Object> *header;
};

template <class Object>
List<Object>::List( )
{
        header = new ListNode<Object>;
}

template <class Object>
bool List<Object>::isEmpty( ) const
{
        return header->next== NULL;
}

template <class Object>
ListItr<Object> List<Object>::zeroth( ) const
{
        return ListItr<Object>( header );
}

template <class Object>
ListItr<Object> List<Object>::first( ) const
{
        return ListItr<Object>( header->next );
}

template <class Object>
int printList( const List<Object> & theList )
{
        int n = 0;
        if( theList.isEmpty( ) )
                cout<< "\n\t!! Empty List !!"<<endl;
        else
        {
                ListItr<Object> itr = theList.first();
                for(; !itr.isPastEnd(); itr.advance()) {
                        cout<<"\t["<<itr.retrieve()<<"] ";
                        n++;
                }
        }
        cout << endl;
        return n;
}

template<class Object>
ListItr<Object> List<Object>::find( const Object &x ) const
{
        ListNode<Object> *itr = header->next;
        while( itr != NULL && itr->element != x ) {
                itr = itr->next;
        }
        if(itr!=NULL) {
                cout<<"ListNode Address is "<<itr<<endl;
        }
        return ListItr<Object>( itr );
}

template<class Object>
int List<Object>::remove( const Object &x )
{
        ListItr<Object> p = findPrevious( x );

        if( p.current->next != NULL)
        {
                ListNode<Object> *oldNode = p.current->next;
                p.current->next = p.current->next->next;
                delete oldNode;
                return 1;
        }
}

template <class Object>
ListItr<Object> List<Object>::findPrevious( const Object &x ) const
{
        ListNode<Object> *itr = header;

        while( itr->next != NULL && itr->next->element != x )
                itr = itr->next;
        return ListItr<Object>( itr );
}

template<class Object>
void List<Object>::insert( const Object &x,const ListItr<Object> &p )
{
        if( p.current != NULL )
                p.current->next = new ListNode<Object>( x, p.current->next );
}

template <class Object>
void List<Object>::makeEmpty( )
{
        while( !isEmpty( ) )
                remove( first( ).retrieve( ) );
}

template<class Object>
List<Object>::~List( )
{
        makeEmpty( );
        delete header;
}
