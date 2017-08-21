#pragma once

class CTcpClient {
private:
	class Impl;
	Impl *pimpl;
public:
	CTcpClient();
	~CTcpClient();
	bool Connect(const char *dst_ip_adr, int dstPort);
	void Close();
	int Send(char *buf, size_t size);
	int Recv(char *buf, size_t size);
	bool Select();
};
