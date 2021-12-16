#ifndef MATRIXLIB_H_
#define MATRIXLIB_H_

#include <vector>
#include <stdexcept>
#include <ostream>
#include <initializer_list>

template <class T> class Matrix{
	public:
		std::vector<std::vector<T>> matrix;
		std::vector<T>& operator[](int i) { return matrix[i]; }
		std::vector<T> operator[](int i) const { return matrix[i]; }
		template <typename M> friend std::ostream& operator<<(std::ostream &os, const Matrix<M>& m);

		int n_dimension;
		int m_dimension;

		Matrix<T>(): n_dimension(0), m_dimension(0) {}

		Matrix<T>(int n_dimension, int m_dimension, T init=0){
			this->n_dimension=n_dimension;
			this->m_dimension=m_dimension;
			matrix.resize(n_dimension);
			for (int i=0; i<n_dimension; i++)
			{
				matrix[i].resize(m_dimension);
				fill(matrix[i].begin(), matrix[i].end(), init);
			}
		}

		Matrix<T>(std::initializer_list<std::initializer_list<T>> list){
			n_dimension=list.size();
			m_dimension=list.begin()->size();
			
			matrix.resize(n_dimension);
			int i=0;
			for (const auto& r : list){
				matrix[i].resize(m_dimension);
				int j=0;
				for (const auto& val : r){
					matrix[i][j]=val;
					j++;
				}
				if (m_dimension!=j)
					std::logic_error("Not a matrix");
				i++;
			}
		}

		Matrix<T>(const Matrix &m){
			matrix=m.matrix;
			n_dimension=m.n_dimension;
			m_dimension=m.m_dimension;
		}

		Matrix<T> operator*(const Matrix<T>& b){
			if(this->m_dimension != b.n_dimension)
				throw std::logic_error("columns(A)!=rows(B)");

			Matrix<T> res_matrix(this->n_dimension, b.m_dimension);

			for(int i=0;i<res_matrix.n_dimension; i++){
				for(int j=0; j<res_matrix.m_dimension; j++){
					T sum=0;
					for(int k=0; k<b.n_dimension; k++)
						sum+=this->matrix[i][k]*b.matrix[k][j];
					res_matrix.matrix[i][j]=sum;
				}
			}
			return res_matrix;
		}

		Matrix<T> operator*(const T& b){
			Matrix<T> res_matrix(this->n_dimension, this->m_dimension);
			for (int i=0; i< this->n_dimension; i++)
				for (int j=0; j<this->m_dimension; j++)
					res_matrix[i][j]=(*this)[i][j]*b;
			return res_matrix;
		}

		Matrix<T> invert(){
			Matrix<T> res_matrix(this->m_dimension, this->n_dimension);
			for (int i=0; i<this->n_dimension; i++)
				for (int j=0; j<this->m_dimension; j++){
					res_matrix.matrix[j][i]=this->matrix[i][j];
				}
			return res_matrix;
		}

};

template <typename M> std::ostream& operator<<(std::ostream &os, const Matrix<M>& m){
	for (int i=0; i<m.n_dimension; i++){	
		for (int j=0; j<m.m_dimension-1; j++)
			os << m.matrix[i][j] << "\t";
		os << m.matrix[i][m.m_dimension-1] << std::endl;	
	}
	return os;
};


#endif /* _MATRIXLIB_H_ */