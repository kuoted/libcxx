//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <map>

// class map

//       iterator begin();
// const_iterator begin() const;
//       iterator end();
// const_iterator end()   const;
//
//       reverse_iterator rbegin();
// const_reverse_iterator rbegin() const;
//       reverse_iterator rend();
// const_reverse_iterator rend()   const;
//
// const_iterator         cbegin()  const;
// const_iterator         cend()    const;
// const_reverse_iterator crbegin() const;
// const_reverse_iterator crend()   const;

#include <map>
#include <cassert>

int main()
{
    {
        typedef std::pair<const int, double> V;
        V ar[] =
        {
            V(1, 1),
            V(1, 1.5),
            V(1, 2),
            V(2, 1),
            V(2, 1.5),
            V(2, 2),
            V(3, 1),
            V(3, 1.5),
            V(3, 2),
            V(4, 1),
            V(4, 1.5),
            V(4, 2),
            V(5, 1),
            V(5, 1.5),
            V(5, 2),
            V(6, 1),
            V(6, 1.5),
            V(6, 2),
            V(7, 1),
            V(7, 1.5),
            V(7, 2),
            V(8, 1),
            V(8, 1.5),
            V(8, 2)
        };
        std::map<int, double> m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        assert(std::distance(m.begin(), m.end()) == m.size());
        assert(std::distance(m.rbegin(), m.rend()) == m.size());
        std::map<int, double>::iterator i = m.begin();
        std::map<int, double>::const_iterator k = i;
        assert(i == k);
        for (int j = 1; j <= m.size(); ++j, ++i)
        {
            assert(i->first == j);
            assert(i->second == 1);
            i->second = 2.5;
            assert(i->second == 2.5);
        }
    }
    {
        typedef std::pair<const int, double> V;
        V ar[] =
        {
            V(1, 1),
            V(1, 1.5),
            V(1, 2),
            V(2, 1),
            V(2, 1.5),
            V(2, 2),
            V(3, 1),
            V(3, 1.5),
            V(3, 2),
            V(4, 1),
            V(4, 1.5),
            V(4, 2),
            V(5, 1),
            V(5, 1.5),
            V(5, 2),
            V(6, 1),
            V(6, 1.5),
            V(6, 2),
            V(7, 1),
            V(7, 1.5),
            V(7, 2),
            V(8, 1),
            V(8, 1.5),
            V(8, 2)
        };
        const std::map<int, double> m(ar, ar+sizeof(ar)/sizeof(ar[0]));
        assert(std::distance(m.begin(), m.end()) == m.size());
        assert(std::distance(m.cbegin(), m.cend()) == m.size());
        assert(std::distance(m.rbegin(), m.rend()) == m.size());
        assert(std::distance(m.crbegin(), m.crend()) == m.size());
        std::map<int, double>::const_iterator i = m.begin();
        for (int j = 1; j <= m.size(); ++j, ++i)
        {
            assert(i->first == j);
            assert(i->second == 1);
        }
    }
}
