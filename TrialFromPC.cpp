//
//  TrialFromPC.cpp
//  Trial
//
//  Created by Athish Rahul Rao on 14/06/17.
//  Copyright © 2017 Athish Rahul Rao. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//TYPELIST
template <typename ...T>
struct Typelist;
template<typename Head, typename ...Tail>
struct Typelist<Head, Tail...>  {
    using H = Head;
    using T = Typelist<Tail...>;
};

//GET LENGTH
template< typename... T >
struct GetLength;
template< typename... T >
struct GetLength <Typelist<T...> >: std::integral_constant<std::size_t, sizeof...(T)>
{ };

//GET ELEMENT
template<typename Ts, typename Tt, typename... T >
struct GetEle;
template<typename Ts, typename Tt, typename... T >
struct GetEle<Ts, Typelist<Tt, T...> >{
    
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct CytoCa {
    static const char name[];
    static const int numb;
    static const double DefaultDiffusionConstant;
};
struct CytoBm {
    static const char name[];
    static const int numb;
    static const double DefaultDiffusionConstant;
};
struct CytoBs {
    static const char name[];
    static const int numb;
    static const double DefaultDiffusionConstant;
};
struct SarcoCa {
    static const char name[];
    static const int numb;
    static const double DefaultDiffusionConstant;
};
struct SarcoBs {
    static const char name[];
    static const int numb;
    static const double DefaultDiffusionConstant;
};

const char CytoCa::name[] = "CytoCa";
const int CytoCa::numb = 0;
const double CytoCa::DefaultDiffusionConstant = 6;

const char CytoBm::name[] = "CytoBm";
const int CytoBm::numb = 1;
const double CytoBm::DefaultDiffusionConstant = 12;

const char CytoBs::name[] = "CytoBs";
const int CytoBs::numb = 2;
const double CytoBs::DefaultDiffusionConstant = 16;

const char SarcoCa::name[] = "SarcoCa";
const int SarcoCa::numb = 3;
const double SarcoCa::DefaultDiffusionConstant = 21;

const char SarcoBs::name[] = "SarcoBs";
const int SarcoBs::numb = 4;
const double SarcoBs::DefaultDiffusionConstant = 23;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
using SL = Typelist<CytoCa, CytoBm, CytoBs, SarcoCa, SarcoBs>;
using CytoCaIL  = Typelist<CytoCa, CytoBm, CytoBs, SarcoCa>; //1,2,3,4
using CytoBmIL = Typelist<CytoCa, SarcoCa, SarcoBs>; //1,4,5
using CytoBsIL = Typelist< CytoBm, CytoBs>; //2,3
using SarcoCaIL = Typelist<CytoCa,CytoBs, SarcoBs>;//1,3,5
using SarcoBsIL = Typelist<CytoBm, SarcoCa, SarcoBs>; // 2,4,5
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class SL, class SIL, typename Real>
class RDMatrix {
public:
    typedef SL SpeciesList;
    typedef SIL SpeciesInteractionList;
    Real X[5];
    
    template <typename ...> struct matVec;
    template <template <typename ...> class List, typename T>
    struct matVec<List<void>, T>
    {
        
        //std::cout<< Tf::DefaultDiffusionConstant*X[Tf::numb] << std::endl;
        //return Tf::DefaultDiffusionConstant*X[Tf::numb];
    };
    /*
    template<typename Tf,   typename...T>
    Real matVec () const {
        //std::cout<< Tf::DefaultDiffusionConstant*X[Tf::numb] + matVec<T...>() << std::endl;
        return Tf::DefaultDiffusionConstant*X[Tf::numb] + matVec<T...>();
    }
    
    template<typename Tf>
    Real unroll () const {
     
        
    } */
    
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main (int argc, char * argv[]){
    std::vector<int> X = {7, 5, 16, 8, 2};
    using KK = Typelist<CytoCaIL, CytoBmIL, CytoBsIL, SarcoCaIL, SarcoBsIL>;
    using mat = RDMatrix<SL,KK, double>;
    mat M;
    //M.matVec<CytoCaIL, CytoBmIL>();
    using a = GetLength<CytoCaIL>;
    return 0;
}

