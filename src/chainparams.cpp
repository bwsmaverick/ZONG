// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include <iostream>

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x47;
        pchMessageStart[1] = 0xa2;
        pchMessageStart[2] = 0x3c;
        pchMessageStart[3] = 0x7b;
        vAlertPubKey = ParseHex("044d8ed9f13b7c14d85758fbc5a2ba124ab7017bc7f349311a30d977881332dd6b0c2f11e5d87a4c3eb6fe261b2f3c0a4dd3d5a84e4cf8fcee7a3a5af5b548dada");
        nDefaultPort = 44321;
        nRPCPort = 44320;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);

        const char* pszTimestamp = "ATMs May Pave Way as Cryptocurrency Seeks Route to Mainstream Adoption";
        std::vector<CTxIn> vin;
        std::vector<CTxOut> vout;
        vin.resize(1);
        vout.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        vout[0].nValue = 0;
        vout[0].scriptPubKey = CScript() << ParseHex("04c629dd47950d15c4f63db4e67247335e09dec8b4ca4c157a23858e2503709e5fe3ba75d5b5263b046ae4b20af135a4dc79e66123ad9a15e65a98798bfee60724") << OP_CHECKSIG;
        CTransaction txNew(1, 1542957092, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = ;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = ;
		
		
/*
nNonce is: 12974417
Hash is: 0000013a7c8f2442bb9f43b11c84f3d8a6a9785465d8740138b08c037807478e
Block is: CBlock(hash=0000013a7c8f2442bb9f43b11c84f3d8a6a9785465d8740138b08c037807478e, ver=1, hashPrevBlock=0000000000000000000000000000000000000000000000000000000000000000, hashMerkleRoot=17535e50176c1dc1d0d8c801021182f395897ffe3c2e5fe016b4f1b81da8b9a6, nTime=1542957092, nBits=1e0fffff, nNonce=12974417, vtx=1, vchBlockSig=)
  Coinbase(hash=17535e50176c1dc1d0d8c801021182f395897ffe3c2e5fe016b4f1b81da8b9a6, nTime=1542957092, ver=1, vin.size=1, vout.size=1, nLockTime=0)
    CTxIn(COutPoint(0000000000, 4294967295), coinbase 00012a4641544d73204d61792050617665205761792061732043727970746f63757272656e6379205365656b7320526f75746520746f204d61696e73747265616d2041646f7074696f6e)
    CTxOut(nValue=0.00, scriptPubKey=04c629dd47950d15c4f63db4e67247335e09dec8b4ca4c157a23858e2503709e5fe3ba75d5b5263b046ae4b20af135a4dc79e66123ad9a15e65a98798bfee60724 OP_CHECKSIG)

  vMerkleTree:  17535e50176c1dc1d0d8c801021182f395897ffe3c2e5fe016b4f1b81da8b9a6

*/

        hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256("0x"));
        assert(genesis.hashMerkleRoot == uint256("0x"));
                
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 80); // Z
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 142); // z
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1, 45); // K
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0x51)(0x17).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xf5)(0xb8).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nLastPOWBlock = 100;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x37;
        pchMessageStart[1] = 0x19;
        pchMessageStart[2] = 0xa7;
        pchMessageStart[3] = 0x4c;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        vAlertPubKey = ParseHex("04cadfb15896c3e0d59e6ef44b87e464a74c6978afe5199dfd9a6916d9cad33ea9307ca7228288416d7737519c36ab052c63e8dedbd047d6c37af6fc66bc943c9d");
        nDefaultPort = 54321;
        nRPCPort = 54320;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = ;
		
        hashGenesisBlock = genesis.GetHash();
		
		
/*
testnet nNonce is: 65510
Hash is: 0000a35375c55d1e5ce9285dff856f590ce0c912dbc4ab94d583ecd56329d912
Block is: CBlock(hash=0000a35375c55d1e5ce9285dff856f590ce0c912dbc4ab94d583ecd56329d912, ver=1, hashPrevBlock=0000000000000000000000000000000000000000000000000000000000000000, hashMerkleRoot=17535e50176c1dc1d0d8c801021182f395897ffe3c2e5fe016b4f1b81da8b9a6, nTime=1542957092, nBits=1f00ffff, nNonce=65510, vtx=1, vchBlockSig=)
  Coinbase(hash=17535e50176c1dc1d0d8c801021182f395897ffe3c2e5fe016b4f1b81da8b9a6, nTime=1542957092, ver=1, vin.size=1, vout.size=1, nLockTime=0)
    CTxIn(COutPoint(0000000000, 4294967295), coinbase 00012a4641544d73204d61792050617665205761792061732043727970746f63757272656e6379205365656b7320526f75746520746f204d61696e73747265616d2041646f7074696f6e)
    CTxOut(nValue=0.00, scriptPubKey=04c629dd47950d15c4f63db4e67247335e09dec8b4ca4c157a23858e2503709e5fe3ba75d5b5263b046ae4b20af135a4dc79e66123ad9a15e65a98798bfee60724 OP_CHECKSIG)

  vMerkleTree:  17535e50176c1dc1d0d8c801021182f395897ffe3c2e5fe016b4f1b81da8b9a6



*/

        assert(hashGenesisBlock == uint256("0x0000a35375c55d1e5ce9285dff856f590ce0c912dbc4ab94d583ecd56329d912"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 65); // T
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 127); // t
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1, 58); // Q
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x19)(0x55).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x25)(0x63).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nLastPOWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    
    bool fTestNet = GetBoolArg("-testnet", false);
    
    if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
