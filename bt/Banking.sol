//SPDX-License-Identifier: MIT 
pragma solidity ^0.8.6;

contract Banks{
    int bal = 1;

    function getBalance() view public returns(int){
        return bal;
    }

    function withdraw(int amt) public{ 
        if (bal >= amt){
            bal -= amt;
        }
    }

    function deposit(int amt) public{
        bal += amt;
    }
}