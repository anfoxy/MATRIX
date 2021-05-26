#include "Vector.h"

template <class ValType>
TVector<ValType>::TVector(int s, int si) {
  Size = s;
  StartIndex = si;
  pVector = new ValType[Size];
  for (int i = 0; i < Size; i++)
  {
    pVector[i] = 0;
  }
}

template <class ValType>
TVector<ValType>::TVector(const TVector &v){
  Size = v.Size;
  StartIndex = v.StartIndex;
  pVector = new ValType[v.Size];
  for (int i = 0; i < Size; i++) {
    pVector[i] = v.pVector[i];
  }
}

template <class ValType>
TVector<ValType>::~TVector() {
  delete[] pVector;
  pVector = nullptr;
}

template <class ValType>
ValType & TVector<ValType>::operator[](int pos) {
  return pVector[pos-StartIndex];
}

template<class ValType>
bool TVector<ValType>::operator==(const TVector & v)
{
  bool flag = 0;
  if ((Size == v.Size) & (StartIndex == v.StartIndex))
  {
    int n = 0;
    for (int i = 0; i < Size; i++)
    {
      if ((pVector[i] == v.pVector[i]))
        n++;
    }
    if (n == Size)
    {
      flag = 1;
    }
  }
  return flag;
}

template <class ValType>
TVector<ValType> & TVector<ValType>::operator=(const TVector &v) {
  if (this != &v) {
    if (Size != v.Size) {
      delete[] pVector;
      pVector = new ValType[v.Size];
    }
    Size = v.Size;
    StartIndex = v.StartIndex;
    for (int i = 0; i < Size; i++) {
      pVector[i] = v.pVector[i];
    }
  }
  return *this;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v) {
  TVector temp(Size, StartIndex);
  for (int i = 0; i < Size; i++)
	temp.pVector[i] = pVector[i] + v.pVector[i];
  return temp;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v) {
  TVector temp(Size, StartIndex);
  for (int i = 0; i < Size; i++)
    temp.pVector[i] = pVector[i] - v.pVector[i];
  return temp;
}

template<class ValType>
TVector<ValType> TVector<ValType>::operator*(const TVector<ValType> &v) {
  TVector temp(1);
  for (int i = 0; i < Size; i++) temp.pVector[0] = (pVector[i] * v.pVector[i]) + temp.pVector[0];
  return temp;
}

template<class ValType>
ValType & TVector<ValType>::GetValue(int pos)
{
  if ((pos < StartIndex) || (pos >= (Size + StartIndex)))
  {
    throw 1;
  }
  return pVector[pos];
}

template<class ValType>
TVector<ValType> TVector<ValType>::operator+(const ValType & val)
{
  TVector temp(Size, StartIndex);
  for (int i = 0; i < Size; i++)
    temp.pVector[i] = pVector[i] + val;
  return temp;
}

template<class ValType>
TVector<ValType> TVector<ValType>::operator-(const ValType & val)
{
  TVector temp(Size, StartIndex);
  for (int i = 0; i < Size; i++)
    temp.pVector[i] = pVector[i] - val;
  return temp;
}

template<class ValType>
TVector<ValType> TVector<ValType>::operator*(const ValType & val)
{
  TVector temp(Size, StartIndex);
  for (int i = 0; i < Size; i++)
    temp.pVector[i] = pVector[i] * val;
  return temp;
}

template class TVector<int>;
template class TVector<TVector<int>>;