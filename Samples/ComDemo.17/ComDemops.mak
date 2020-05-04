
ComDemops.dll: dlldata.obj ComDemo_p.obj ComDemo_i.obj
	link /dll /out:ComDemops.dll /def:ComDemops.def /entry:DllMain dlldata.obj ComDemo_p.obj ComDemo_i.obj kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib uuid.lib 

.c.obj:
	cl /c /Ox /DWIN32 /DREGISTER_PROXY_DLL $<

clean:
	@del ComDemops.dll
	@del ComDemops.lib
	@del ComDemops.exp
	@del dlldata.obj
	@del ComDemo_p.obj
	@del ComDemo_i.obj
