#include "matrix.h"
template <class ValType>
TMatrix<ValType>::TMatrix(int s):TVector<TVector<ValType>>(s) {
  for (int i = 0; i < s; i++) this->pVector[i] = TVector<ValType>(s-i,i);
}

template <class ValType>
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt) : TVector<TVector<ValType>>(mt) {}

template <class ValType>
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType>> &mt) : TVector<TVector<ValType>>(mt) {}

template<class ValType>
bool TMatrix<ValType>::operator==(const TMatrix & mt){return  TVector<TVector<ValType>>::operator==(mt);}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt){return  TVector<TVector<ValType>>::operator+(mt);}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt){return  TVector<TVector<ValType>>::operator-(mt);}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator* (const TMatrix& mt) {
  TMatrix<ValType> temp(this->GetSize());
  int i, j, k;
  for (i = 0; i < temp.Size; ++i)
    for (j = i; j < temp.Size; ++j)
      for (k = i; k < j + 1; ++k)
        temp[i][j] += this->pVector[i][k] * mt.pVector[k][j];
  return temp;
}

template <class ValType>
TMatrix<ValType>&TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
  if (this != &mt)
  {
    if (this->Size != mt.Size)
    {
      delete[] this->pVector;
	    this->pVector = new TVector<ValType>[mt.Size];
    }
	  this->Size = mt.Size;
	  this->StartIndex = mt.StartIndex;
    for (int i = 0; i < this->Size; i++)
		this->pVector[i] = mt.pVector[i];
  }
  return *this;
}
template class TMatrix<int>;