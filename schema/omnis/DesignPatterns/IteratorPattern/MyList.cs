
using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;

namespace IteratorPattern
{
    //public class MyList
    //{
    //    private readonly int[] f;

    //    public MyList(int n)
    //    {
    //        f = new int[n];
    //    }

    //    public void Add(int n)
    //    {
    //        f[n]++;
    //    }
    //}

    public class MyList : IEnumerable<int>
    {
        private readonly int[] f;
        private readonly int n;

        public MyList(int n)
        {
            this.n = n;
            f = new int[n];
        }

        public void Add(int i)
        {
            f[i]++;
        }

        public IEnumerator<int> GetEnumerator()
        {
            for (int i = 0; i < n; ++i)
                for (int j = f[i]; j > 0; --j)
                    yield return i;
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }

    //public class MyList : IEnumerable<int>
    //{
    //    private readonly int[] f;
    //    private readonly int n;

    //    public MyList(int n)
    //    {
    //        this.n = n;
    //        f = new int[n];
    //    }

    //    public void Add(int i)
    //    {
    //        f[i]++;
    //    }

    //    public IEnumerator<int> GetEnumerator()
    //    {
    //        return new MyListEnumerator(this);
    //    }

    //    IEnumerator IEnumerable.GetEnumerator()
    //    {
    //        return GetEnumerator();
    //    }

    //    private class MyListEnumerator : IEnumerator<int>
    //    {
    //        private readonly MyList list;
    //        private int pos;
    //        private int count;

    //        public int Current { get { return pos; } }
    //        object IEnumerator.Current { get { return Current; } }

    //        public MyListEnumerator(MyList myList)
    //        {
    //            list = myList; Reset();
    //        }

    //        public bool MoveNext()
    //        {
    //            if (count > 0) { count--; return true; }

    //            do { pos++; } while (pos < list.n && list.f[pos] == 0);

    //            if (pos == list.n) return false;

    //            count = list.f[pos] - 1;
    //            return true;
    //        }

    //        public void Reset() { pos = -1; count = 0; }
    //        public void Dispose() { }
    //    }
    //}
}
