#pragma once

#include "sqrl.h"
#include "SqrlTransaction.fwd.h"

#define SQRL_ENCRYPT 1
#define SQRL_DECRYPT 0
#define SQRL_MILLIS 2
#define SQRL_ITERATIONS 0

class DLL_PUBLIC SqrlCrypt
{
public:
	static int enScrypt( SqrlTransaction *transaction,
		uint8_t *buf, const char *password, size_t password_len,
		const uint8_t *salt, uint8_t salt_len,
		uint16_t iterations, uint8_t nFactor = 9 );
	static int enScryptMillis( SqrlTransaction *transaction,
		uint8_t *buf, const char *password, size_t password_len,
		const uint8_t *salt, uint8_t salt_len,
		int millis, uint8_t nFactor = 9 );
	static int enHash( uint64_t *out, const uint64_t *in );
	static int encrypt( uint8_t *cipherText, const uint8_t *plainText, size_t textLength,
		const uint8_t *key, const uint8_t *iv, const uint8_t *add, size_t add_len, uint8_t *tag );
	static int decrypt( uint8_t *plainText, const uint8_t *cipherText, size_t textLength,
		const uint8_t *key, const uint8_t *iv, const uint8_t *add, size_t add_len, const uint8_t *tag );
	static void generateIdentityLockKey( uint8_t ilk[SQRL_KEY_SIZE], const uint8_t iuk[SQRL_KEY_SIZE] );
	static void generateLocalKey( uint8_t local[SQRL_KEY_SIZE], const uint8_t mk[SQRL_KEY_SIZE] );
	static void generateMasterKey( uint8_t mk[SQRL_KEY_SIZE], const uint8_t iuk[SQRL_KEY_SIZE] );
	static void generateRandomLockKey( uint8_t rlk[SQRL_KEY_SIZE] );
	static void generateServerUnlockKey( uint8_t suk[SQRL_KEY_SIZE], const uint8_t rlk[SQRL_KEY_SIZE] );
	static void generateVerifyUnlockKey( uint8_t vuk[SQRL_KEY_SIZE], const uint8_t ilk[SQRL_KEY_SIZE], const uint8_t rlk[SQRL_KEY_SIZE] );
	static void generateUnlockRequestSigningKey( uint8_t ursk[SQRL_KEY_SIZE], const uint8_t suk[SQRL_KEY_SIZE], const uint8_t iuk[SQRL_KEY_SIZE] );
	static void generatePublicKey( uint8_t *puk, const uint8_t *prk );
	static void sign( const UT_string *msg, const uint8_t sk[32], const uint8_t pk[32], uint8_t sig[64] );
	static bool verifySignature( const UT_string *msg, const uint8_t *sig, const uint8_t *pub );
	static void generateCurvePrivateKey( uint8_t *key );
	static void generateCurvePublicKey( uint8_t *puk, const uint8_t *prk );
	static int generateSharedSecret( uint8_t *shared, const uint8_t *puk, const uint8_t *prk );


	uint8_t *plain_text = NULL;
	uint8_t *cipher_text = NULL;
	uint16_t text_len = 0;
	uint8_t *add = NULL;
	uint16_t add_len = 0;
	uint8_t *tag = NULL;
	uint8_t *salt = NULL;
	uint8_t *iv = NULL;
	uint32_t count = 0;
	uint8_t nFactor = 9;
	uint8_t flags = SQRL_ENCRYPT | SQRL_ITERATIONS;

private:
	uint8_t *key;
};