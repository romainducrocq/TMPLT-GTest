#ifndef _EX_EX_HPP
#define _EX_EX_HPP

#include <cassert>
#include <cmath>

#include <vector>

namespace ex
{
    struct Matrix
    {
        public :
            template <typename T>
            static inline float dot(const std::vector<T>& x, const std::vector<T>& y)
            {
                assert(x.size() == y.size());

                T sum = 0.f;
                for(size_t i = 0; i < x.size(); i++) {
                    sum += x[i] * y[i];
                }

                return sum;
            }

            template <typename T>
            static inline void add(std::vector<T>& x, const std::vector<T>& y)
            {
                assert(x.size() == y.size());

                for(size_t i = 0; i < x.size(); i++) {
                    x[i] += y[i];
                }
            }
    };

    struct Activation
    {
        public:
            static inline void sigmoid(std::vector<float>& z)
            {
                for(auto& zi : z) {
                    zi = 1.f / (1.f + std::exp(-zi));
                }
            }

            static inline void relu(std::vector<float>& z)
            {
                for(auto& zi : z) {
                    zi = zi > 0.f ? zi : 0.f;
                }
            }

            static inline void elu(std::vector<float>& z)
            {
                float a = 1.f;
                for(auto& zi : z) {
                    zi = zi > 0.f ? zi : a * (std::exp(zi) - 1.f);
                }
            }

            static inline void softmax(std::vector<float>& z){
                float sum = 0.f;

                for(const auto zj : z) {
                    sum += std::exp(zj);
                }

                for(auto& zi : z) {
                    zi = std::exp(zi) / sum;
                }
            }
    };
}

#endif
