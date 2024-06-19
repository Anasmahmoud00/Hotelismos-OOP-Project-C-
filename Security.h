#pragma once
#ifndef SECURITY_H
#define SECURITY_H


class Security {
private:
	int receipts[10] = { 520, 521, 522, 523, 524, 525, 526, 527, 528 };
public:
	bool verifyPayment(int pReceipt);
};


#endif

