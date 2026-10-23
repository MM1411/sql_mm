# SQLMM

SQLMM provides simple non-blocking MySQL/SQLite connectors for MetaMod.

> [!IMPORTANT]
> Linux builds require the `default-libmysqlclient-dev` package to be installed.

# Features

- Non-blocking MySQL/SQLite queries/transactions
- Windows & Linux support
- Simple API

# Interface

SQLMM will expose an interface in `OnMetamodQuery` which can then be queried with `(ISQLInterface*)g_SMAPI->MetaFactory(SQLMM_INTERFACE, &ret, NULL);` by other plugins.
Example:
```c++
  ISQLiteClient *g_pSQLiteClient;
	g_pSQLiteClient = ((ISQLInterface *)g_SMAPI->MetaFactory(SQLMM_INTERFACE, nullptr, nullptr))->GetSQLiteClient();
	g_SMAPI->PathFormat(buffer, sizeof(buffer), "path/to/database/db.sqlite3");
	if (g_pSQLiteClient)
	{
		SQLiteConnectionInfo info;
		info.database = buffer;
		conn = g_pSQLiteClient->CreateSQLiteConnection(info);
		conn->Connect(
			[](bool success)
			{
        //...
			});
	}
```

Interface definition can be found in `src/public`.

## Compilation

### Requirements

- [Metamod:Source](https://github.com/alliedmodders/metamod-source) 2.0 build 1411
  (`465f1a02081996a0eb0665a9fa0189c092a82936`), the last build that uses SourceHook. Later builds switched to KHook,
  which this fork does not support.
- [s2sdk](https://github.com/alliedmodders/s2sdk), `cs2` branch. The `cs2` branch of hl2sdk is no longer maintained.
- [AMBuild](https://wiki.alliedmods.net/Ambuild)
- On Linux, the `default-libmysqlclient-dev` and `lld` packages.

```bash
git clone https://github.com/zer0k-z/sql_mm && cd sql_mm
git submodule update --init

export MMSOURCE20=/path/to/metamod-source/
export HL2SDKCS2=/path/to/hl2sdk-cs2

mkdir build && cd build
python3 ../configure.py -s cs2
ambuild
```

The package is written to `build/package`.
