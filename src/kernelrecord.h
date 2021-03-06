#ifndef BITCOIN_KERNELRECORD_H
#define BITCOIN_KERNELRECORD_H

#include <amount.h>
#include <uint256.h>

namespace interfaces {
class Node;
class Wallet;
struct WalletTx;
struct WalletTxStatus;
struct WalletTxOut;
}

class KernelRecord
{
public:
    KernelRecord():
        hash(), nTime(0), address(""), nValue(0), coinAge(0), prevMinutes(0), prevDifficulty(0), prevProbability(0)
    {
    }

    KernelRecord(uint256 hash, int64_t nTime):
            hash(hash), nTime(nTime), address(""), nValue(0), coinAge(0), prevMinutes(0), prevDifficulty(0), prevProbability(0)
    {
    }

    KernelRecord(uint256 hash, int64_t nTime,
                 const std::string &address,
                 int64_t nValue, int64_t coinAge):
        hash(hash), nTime(nTime), address(address), nValue(nValue),
        coinAge(coinAge), prevMinutes(0), prevDifficulty(0), prevProbability(0)
    {
    }

    static bool showTransaction();
    static std::vector<KernelRecord> decomposeOutput(const COutPoint& output, const interfaces::WalletTxOut& out);


    uint256 hash;
    int64_t nTime;
    std::string address;
    int64_t nValue;
    int idx;
    int64_t coinAge;

    std::string getTxID();
    int64_t getAge() const;
    uint64_t getCoinDay() const;
    double getProbToMintStake(double difficulty, int timeOffset = 0) const;
    double getProbToMintWithinNMinutes(double difficulty, int minutes);
    int64_t getPoSReward(int minutes);
protected:
    int prevMinutes;
    double prevDifficulty;
    double prevProbability;
};

#endif // BITCOIN_KERNELRECORD_H
