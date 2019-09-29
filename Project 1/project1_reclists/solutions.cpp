#include "reclists.hpp"
#include "solutions.hpp"

// As you implement functions in this file, you should add the
// function-prototype to the solutions.hpp. The function-prototypes
// for append and reverse are already in solutions.hpp.

int numSublists(list p)
{
    if (is_null(p))
    {
        return 0;
    }

    return numSublists(cdr(p)) + 1;
}

list nthSublist(list p, int n)
{
    if (n == 1)
    {
        return car(p);
    }

    return nthSublist(cdr(p), n - 1);
}

int numAtoms(list p)
{
    if (is_null(p))
    {
        return 0;
    }

    if (is_atom(car(p)))
    {
        return 1 + numAtoms(cdr(p));
    }

    return numAtoms(cdr(p));

}

bool member(list p, list q)
{
    // p is an atom. q is a list of atoms. The function
    // returns true if p is one of the atoms in q. Otherwise,
    // it return false.
    if (is_null(q))
    {
        return false;
    }
    if (is_atom(car(q)))
    {
        if (eq(p, car(q)))
        {
            return true;
        }
        else
        {

            return member(p, cdr(q));
        }
    }
    else
    {
        if (member(p, car(q)))
        {
            return true;
        }
        else
        {
            return member(p, cdr(q));
        }
    }
}

list append(list p, list q)
{
    if (is_null(p))
    {
        return q;
    }
    return cons(car(p), append(cdr(p), q));
}

list atomsAtLevel(list p, int level)
{
    if (level == 0 || is_null(p))
    {
        return null();
    }

    if (is_atom(car(p)))
    {
        return level == 1 ? cons(car(p), atomsAtLevel(cdr(p), level)) :
               atomsAtLevel(cdr(p), level);
    }
    return append(atomsAtLevel(car(p), level - 1), atomsAtLevel(cdr(p), level));
}

bool is_lat(list p)
{

    if (is_null(p))
    {
        return true;
    }

    if (is_atom(car(p)))
    {
        return is_lat(cdr(p));
    }
    return false;

}

list last(list p)
{


    if (is_null(p))
    {
        return 0;
    }

    if (is_null(cdr(p)))
    {
        return car(p);
    }
    return last(cdr(p));
}


list firsts(list p)
{
    if (is_null(p))
    {
        return null();
    }
    if (is_atom(car(p)))
    {
        return cons(car(p), null());
    }
    else
    {
        return append(firsts(car(p)), firsts(cdr(p)));
    }
}


bool two_the_same(list p, list q)
{
    if (is_null(p) || is_null(q))
    {
        return 0;
    }
    if (is_atom(car(p)))
    {
        if (member(car(p), q))
        {
            return true;
        }
        else
        {
            return two_the_same(cdr(p), q);
        }
    }
    else
    {
        if (two_the_same(car(p), q))
        {
            return true;
        }
        else
        {
            return two_the_same(cdr(p), q);
        }
    }


}

list flat(list p)
{
    if (is_null(p))
    {
        return null();
    }
    if (is_atom(car(p)))
    {
        return cons(car(p), flat(cdr(p)));
    }
    else
    {
        return append(flat(car(p)), flat(cdr(p)));
    }

}

list permute(list p)
{ // Close to the correct output for (a b c d) input
    std::cout << " In flat" << std::endl;
    if (is_null(p))
    {
        std::cout << "inside is null p for Flat" << std::endl;
        return 0;
    }
    if (is_atom(car(p)))
    {
        std::cout << " Inside is_atom for Car in Flat" << std::endl;
        if (is_null(cdr(p)))
        {
            std::cout << " Inside is_null cdr of P for Car in Flat" << std::endl;
            return null();
        }
        else
        {

            std::cout << " Inside ELSE of is_null cdr of P for Car in Flat" << std::endl;

            return cons(car(p), flat(cdr(p)));
        }
    }
    else
    {
        if (is_atom(flat(car(p))))
        {
            std::cout << " Inside Not Atom for car in Flat" << std::endl;
            return append(flat(car(p)), flat(cdr(p)));
        }
        std::cout << " Outside of end statment" << std::endl;

    }

}

list list_pair(list p, list q)
{
    if (is_null(p) || is_null(q))
    {
        return null();
    }
    if (is_atom(car(p)) && is_atom(car(q)))
    {
        return cons(cons(car(p), cons(car(q), null())), list_pair(cdr(p), cdr(q)));
    }
    else
    {
        if (is_atom(car(p)))
        {
            return cons(p, list_pair(p, cons(car(q), null())));
        }
        else if (is_atom(car(q)))
        {
            return cons(list_pair(car(p), q), cons(q, null()));
        }
    }


}

bool equal(list p, list q)
{
    if (is_null(p) && is_null(p))
    {
        return true;
    }

    if (is_atom(car(p)) && is_atom(car(q)))
    {
        if (eq(car(p), car(q)))
        {
            return equal(cdr(p), cdr(q));
        }
        return false;
    }
    else
    {
        if (is_atom(car(p)) || is_atom(car(q)))
        {
            return false;
        }
        else
        {
            return equal(car(p), car(q));
        }
    }

}

list shape(list p)
{
    if (is_null(p))
    {
        return null();
    }
    if (is_atom(car(p)))
    {
        return null();
    }
    else
    {
        return cons(shape(car(p)), shape(cdr(p)));
    }

}

list total_reverse(list p)
{
    if (is_null(p))
    {
        return null();
    }
    if (is_atom(car(p)))
    {
        return append(total_reverse(cdr(p)), cons(car(p), null()));
    }
    else
    {
        return append(total_reverse(cdr(p)), cons(total_reverse(car(p)), null()));
    }
}

list intersection(list p, list q)
{
    if (is_null(p))
    {
        return null();
    }
    if (is_atom(car(p)))
    {
        if (member(car(p), q))
        {
            return append(cons(car(p), null()), intersection(cdr(p), q));
        }
        return intersection(cdr(p), q);
    }
    else
    {
        return append(intersection(car(p), q), intersection(cdr(p), q));
    }
}

list list_union(list p, list q)
{
    if (is_null(p) || is_null(q))
    {
        return null();
    }
    if (is_atom(car(p)) || is_atom(q))
    {
        if (member(car(p), q))
        {
            std::cout << " Is member" << std::endl;
            return append(list_union(cdr(p), q), q);
        }
        if (member(car(q), p))
        {
                std::cout << " q is atom" << std::endl;
                return append(list_union(p, cdr(q)), cons(car(q), null()));
        }

        std::cout << " after if member" << std::endl;
        return append(append(cons(car(p), null()), list_union(cdr(p), q)), list_union(p, car(q)));

    }
    else
    {
        std::cout << " else after is atom" << std::endl;
        return append(append(append(list_union(car(p), q), list_union(cdr(p), q)), list_union(p, car(q))),
                      list_union(p, cdr(q)));
    }


}