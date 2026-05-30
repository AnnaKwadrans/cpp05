#include <stdexcept>

void    test1()
{
        try
        {
                // do something
                if (/* error */)
                {
                        throw std::exception();
                }
                else
                {
                        // do something else
                }
        }
        catch (std::exception e)
        {
                // handle the error
        }
}

/*********************/

void    test2()
{
        // do something
        if (/* error */)
        {
                throw std::exception();
        }
        else
        {
                // do something else
        }
}

void    test3()
{
        try
        {
                test2();
        }
        catch (std::exception& e) // by reference
        {
                // handle the error
        }

}

/*********************/

void    test4()
{
        class PEBKACException : public std::exception
        {
                public:

                        virtual const char* what() const throw()
                        {
                                return ("Problem exists between keyboard and chair");
                        }
        };

        try
        {
                test3();
        }
        catch (PEBKACException& e)
        {
                // handle error
        }
        catch (std::exception& e)
        {
                // handle other error
        }
}

