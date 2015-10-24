::本程序来源于网络共享
::如对本程序有任何建议，请直接在github上留下你的建议

::mode为allow时启动虚拟网卡，disallow时直接禁用虚拟网卡
::ssid为WiFi热点信号名称，key为密码
::由于无法在创建热点的时候获得对应网络的名称，而无法自动设置ip地址
netsh wlan set hostednetwork mode=allow ssid=abc key=123456789

::如果能够启动热点，自动退出，否则停留在控制台上。
netsh wlan start hostednetwork || pause

::此外，启动热点后需要再手动设置网络共享和ip地址
::这些功能将在以后的版本添加
