package webClient.backEnd;

/**
 * This class simply holds string variables that represent commands that can be
 * sent to the PDC.
 * 
 * @author Alexander Bonomo
 */
public interface PDCCommands {
	public static final String DATA_RECORD_CONTENT = "/manage/getcontent";

	public static final String DATA_RECORD_LIST = "/manage/list/datarecords";

	public static final String LOGIN = "/manage/login";
}
